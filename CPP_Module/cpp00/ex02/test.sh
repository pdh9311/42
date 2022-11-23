make re
./account > account.log
awk '{print $2}' 19920104_091532.log > t1
awk '{print $2}' account.log > t2
diff -y t1 t2
rm -rf t1 t2 account.log
make fclean