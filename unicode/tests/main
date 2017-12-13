fichiers=$(ls test_*)

test_description='OSEF'
. sharness.sh

i=0

for fichier in $fichiers ; do
	while IFS='' read -r line || [[ -n "$line" ]]; do
		$fichier "test $i" " 
			$line
		"
		i++
	done < ../$fichier
done
	
test_done	
