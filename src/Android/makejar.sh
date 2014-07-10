#!/bin/sh
#说明：第一个参数为本机android.jar所在路径。
makefunc(){
cd ./src
javac -cp .:$1/android.jar xc/api/*.java
#javac -cp .:/develop/android-sdk-linux/platforms/android-14/android.jar xc/api/*.java
jar cvf xC.jar xc/api/*.class
rm -rf xc/api/*.class
mv xC.jar ../
}
makefunc $1
