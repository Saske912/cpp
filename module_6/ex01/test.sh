if [ $1 ]
then
  N=$1
else
  N=10
fi
while [ "$N" -ne 0 ]
do
  ./serialize
  N=$[$N-1]
  sleep 1
done