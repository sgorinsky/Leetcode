awk 'NR==10' file.txt

line_num=1
cat file.txt | while read line; 
do
    if [[ $line_num == 10 ]]; 
    then
        echo $line
        exit
    fi
    ((line_num++))
done

i=0
cat file.txt | while read line; do
    ((i++))
    [ i -eq 10 ] && echo $line && exit
done


