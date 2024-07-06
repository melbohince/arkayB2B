//%attributes = {}
/*
 Method: _migrations   ( ) ->
 By: MelvinBohince @ 07/06/24, 08:45:35
 Description:
  init table data

 Example Use:
  use Run menu
*/


var $tradingPartners_es : cs:C1710.Trading_PartnersSelection
var $tradingPartner_e : cs:C1710.Trading_PartnersEntity
var $webUsers_es : cs:C1710.Web_UsersSelection
var $webUser_e : cs:C1710.Web_UsersEntity
var $encodedUser : Text

//Trading_Partners
$tradingPartners_es:=ds:C1482.Trading_Partners.all()
$tradingPartners_es.drop()  //start fresh

$tradingPartner_e:=ds:C1482.Trading_Partners.new()
$tradingPartner_e.RegisteredIP:="127.0.0.1"
$tradingPartner_e.EndPoint:="ELCAriba"
$tradingPartner_e.save()

//Web_Users
$webUsers_es:=ds:C1482.Web_Users.all()
$webUsers_es.drop()  //start fresh

$webUser_e:=ds:C1482.Web_Users.new()
$webUser_e.Username:="ELC Ariba User"
$webUser_e.Password:="xxx"
BASE64 ENCODE:C895($webUser_e.Username+":"+$webUser_e.Password; $encodedUser)
$webUser_e.BasicAuthentication:="Basic "+$encodedUser
$webUser_e.EndPoint:="ELCAriba"
$webUser_e.save()

