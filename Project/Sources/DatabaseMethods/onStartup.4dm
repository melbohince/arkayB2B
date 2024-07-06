/*
 Method: On Startup   ( ) ->
 By: MelvinBohince @ 07/06/24, 09:20:39
 Description:
  populate data if first use

  
*/

var $tradingPartners_es : cs:C1710.Trading_PartnersSelection
var $webUsers_es : cs:C1710.Web_UsersSelection

$tradingPartners_es:=ds:C1482.Trading_Partners.all()
$webUsers_es:=ds:C1482.Web_Users.all()

If ($tradingPartners_es.length=0) && ($webUsers_es.length=0)
	_migrations
End if 
