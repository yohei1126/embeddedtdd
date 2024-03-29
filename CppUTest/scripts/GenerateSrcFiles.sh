#!/bin/bash -x
#---
# Excerpted from "Test Driven Development for Embedded C",
# published by The Pragmatic Bookshelf.
# Copyrights apply to this code. It may not be used to create training material, 
# courses, books, articles, and the like. Contact us if you are in doubt.
# We make no guarantees that this code is fit for any purpose. 
# Visit http://www.pragmaticprogrammer.com/titles/jgade for more book information.
#---
#$1 is the template root file name
#$2 is the kind of file to create (c or cpp)
#$3 is Mock if a mock version should be created, Fake for a fake C version
#$4 is the class/module name
#$5 is the package name

#Test for env var set.
checkForCppUTestToolsEnvVariable() {
	if [ -z "$CPP_U_TEST" ] ; then
	   echo "CPP_U_TEST not set"
	   exit 1
	fi
	if [ ! -d "$CPP_U_TEST" ] ; then
	   echo "CPP_U_TEST not set to a directory"
	   exit 2
	fi
}

checkForCppUTestToolsEnvVariable

templateRootName=$1
srcSuffix=$2
mock=$3
className=$4
packageName=$5
testSuffix=Test

#CPP_SOURCE_TEMPLATES can point to templates you write
#identify the template files
if [ "$CPP_SOURCE_TEMPLATES" == "" ]
  then
    TEMPLATE_DIR=$CPP_U_TEST/scripts/templates
  else
    TEMPLATE_DIR=$CPP_SOURCE_TEMPLATES
fi
  
templateHFile=$TEMPLATE_DIR/$templateRootName.h
templateSrcFile=$TEMPLATE_DIR/$templateRootName.$srcSuffix
if [ "$mock" == "Mock" ] ; then
  templateTestFile=$TEMPLATE_DIR/Interface$testSuffix.cpp
elif [ "$mock" == "Fake" ] ; then
  templateTestFile=$TEMPLATE_DIR/InterfaceC$testSuffix.cpp
else
  templateTestFile=$TEMPLATE_DIR/$templateRootName$testSuffix.cpp
fi
templateMockFile=$TEMPLATE_DIR/Mock$templateRootName.h

#indentify the class and instance names
instanceName=$(echo $className | cut -c1 | tr A-Z a-z)$(echo $className | cut -c 2-) 
className=$(echo $className | cut -c1 | tr a-z A-Z)$(echo $className | cut -c 2-)

#if a package is specified, set the directories
if [ ! "$packageName" == "" ]
  then
    srcDir=src/$packageName/
    includeDir=include/$packageName/
    testsDir=tests/$packageName/
  fi

#identify the files being created
hFile=${includeDir}${className}.h
srcFile=${srcDir}${className}.${srcSuffix}
testFile=${testsDir}${className}${testSuffix}.cpp
if [ "$mock" != "NoMock" ] ; then
  mockFile=${testsDir}${mock}${className}.h
  testFile=${testsDir}${mock}${className}${testSuffix}.cpp
  if [ "$srcSuffix" == "c" ] ; then
	srcFile=${testsDir}${mock}${className}.${srcSuffix}
  fi
else
  mockFile=
fi

sedCommands="-e s/aClassName/$instanceName/g -e s/ClassName/$className/g"
 
generateFileIfNotAlreadyThere() {
  if [ -e $2 ]
    then 
      echo "${2} already exists, skipping"
    else
      echo "creating ${2}"
      sed $sedCommands $1 | tr -d "\r" >$2
    fi
}

generateFileIfNotAlreadyThere $templateHFile $hFile
generateFileIfNotAlreadyThere $templateSrcFile $srcFile
generateFileIfNotAlreadyThere $templateTestFile $testFile
if [ "$mock" != "NoMock" ] ; then
  generateFileIfNotAlreadyThere $templateMockFile $mockFile
#  sed $sedCommands $templateMockFile | tr -d "\r" >$mockFile
fi

