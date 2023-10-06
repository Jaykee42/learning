#!/data/data/com.termux/files/usr/bin/bash

cp -f -r ~/storage/downloads/Learning ~/storage/downloads/coding/learning/; 

git add -A;

git commit -am "$1";

git push;


