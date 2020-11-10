#!/bin/bash

#who is running this program
if [ ! $UID = 0 ] ; then
	echo "Must run as root user"
	exit 1
fi

#add user group
#-f will continue after this command even if the group is already added
groupadd -f CSI230

#iterate through arguments given
while getopts ":f:" options;
do
  case "${options}" in
	f)
	   f=${OPTARG} 
	   if [ ! -f $f ];
	   then
		 echo "File does not exist"
		 exit 1
	   fi
	;;

        *)
	  opt=${OPTARG}
	  echo "No such argument: $opt"
	  exit 1
	;;
  esac
done

#for every user
while read line
do
  #parse name from account
  newU=$(echo $line | cut -d'@' -f 1 )
  echo $newU

  #Generate new Passcode
  newPass=$(openssl rand -base64 5)
  echo $newPass

  #user existance test
  getent passwd $newU  > /dev/null
  #Check last exit command to see if user exists
  if [ ! $? -eq 0 ]; then
	useradd -m -g'CSI230' -p$newPass $newU
	echo "Created new user: $newU"
  else
	echo "User exists: expiring password"
  fi

  chage -d 0 $newU

email_body="Hello $newU, your password is $newPass"
email_subject="LINUX:Updated Password"
email_to="benjamin.strong@mymail.champlain.edu"

echo -e "${email_body}" | s-nail -S smtp-use-starttls -S ssl-verify=ignore -S smtp-auth=login -S smtp="<smtp_server>:<smtp_port>" -S smtp-auth-user="<smtp_user>" -S smtp-auth-password="<smtp_password>" -r <from_address> -s "${email_subject}" -. "${email_to}"

done < $f

exit 0









