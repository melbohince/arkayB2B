//%attributes = {}
/*
 Method: OWA_Authenticate   ( ) ->
 By: MelvinBohince @ 07/11/24, 09:30:51
 Description:
  respond to /WebFolder/authenticate.shtml

see Example @ https://developer.4d.com/docs/WebServer/sessions/#storing-and-sharing-session-information

 Example Use:
  <FORM ACTION="/4DACTION/OWA_Authenticate" METHOD=POST>
    UserId: <INPUT TYPE=TEXT NAME=userId VALUE=""><br/>
    Password: <INPUT TYPE=TEXT NAME=password VALUE=""><br/>
   <INPUT TYPE=SUBMIT NAME=OK VALUE="Log In">
  </FORM>
*/

var $indexHit : Integer
var $username; $password; $name; $goodPassword; $mySecret : Text
var $user_e : cs:C1710.Web_UsersEntity

ARRAY TEXT:C222($names_a; 0)
ARRAY TEXT:C222($values_a; 0)

WEB GET VARIABLES:C683($names_a; $values_a)

$indexHit:=Find in array:C230($names_a; "userId")
$username:=$values_a{$indexHit}

$indexHit:=Find in array:C230($names_a; "password")
$password:=$values_a{$indexHit}

//this would be a query against web users
$user_e:=ds:C1482.Web_Users("Username = :1"; $username).first()
If ($user_e=Null:C1517)
	WEB SEND TEXT:C677("This userId is unknown")
	return 
End if 

$goodPassword:="xxx"
$name:="John Doe"
$mySecret:="hard coded credentials"

If ($username#"mel")
	WEB SEND TEXT:C677("This userId is unknown")
	return 
End if 

If (Not:C34(Verify password hash:C1534($password; $goodPassword)))
	WEB SEND TEXT:C677("This password is wrong")
	return 
End if 

$info:=New object:C1471()
$info.userName:=$name

Session:C1714.setPrivileges($info)
Use (Session:C1714.storage)
	If (Session:C1714.storage.mySecret=Null:C1517)
		$mySecret:="Ask for more..."
		Session:C1714.storage.mySecret:=$mySecret
	End if 
End use 

WEB SEND HTTP REDIRECT:C659("/authenticationOK.shtml")
