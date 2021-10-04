echo "commit id,author,date,comment,changed files,lines added,lines deleted" > res.csv 
git log --since=2017-09-01 --until=2020-09-28 --date=local --pretty="%x40%h%x2C%an%x2C%ad%x2C%x22%s%x22%x2C" --shortstat | tr "\n" " " | tr "@" "\n" >> res.csv
sed -i 's/ files changed//g' res.csv
sed -i 's/ file changed//g' res.csv
sed -i 's/ insertions(+)//g' res.csv
sed -i 's/ insertion(+)//g' res.csv
sed -i 's/ deletions(-)//g' res.csv
sed -i 's/ deletion(-)//g' res.csv