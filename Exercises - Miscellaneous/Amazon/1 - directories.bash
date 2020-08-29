
# write your code in Bash

folders='music images videos'
ext_music="*.mp3 *.flac"
ext_images="*.jpg *.png"
ext_videos="*.mov *.avi"

for folder in $folders
do
	if [ $folder == 'music' ]
	then
		mkdir -p $folder
		mv $ext_music $folder 2>/dev/null

	elif [ $folder == 'images' ]
	then
		mkdir -p $folder
		mv $ext_images $folder 2>/dev/null

	elif [ $folder == 'videos' ]
	then
		mkdir -p $folder
		mv $ext_videos $folder 2>/dev/null
	fi
done

rm *.log