#!/bin/sh
make
echo -e "\033[33m ════Test des lexemes════\033[0m"
echo -e "\033[34m"
./analyse_lexicale tests/analyse_lexicale.b
echo -e "\033[0m"
echo -e "\033[33m ════Test de syntaxe ASCII════\033[0m"

for f in tests/ascii/*.b
do
  echo -e "\033[32mTEST :"
  echo $f| cut -d'/' -f 4
  echo -e "\033[0m"
  cat $f
  echo -e "\033[34m"
  python test.py $f  
  echo -e "\033[0m"
done

echo -e "\033[33m ════Test de syntaxe decimal════\033[0m"

for f in tests/decimal/*.b
do
  echo -e "\033[32mTEST :"
  echo $f| cut -d'/' -f 4
  echo -e "\033[0m"
  cat $f
  echo -e "\033[34m"
  python testd.py $f
  echo -e "\033[0m"
done
