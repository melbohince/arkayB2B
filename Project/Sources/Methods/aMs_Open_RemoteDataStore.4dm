//%attributes = {}
/*
 Method: aMs_Open_RemoteDataStore   ( ) ->
 By: MelvinBohince @ 01/24/23, 19:08:47
 Description:
    get ds object for aMs from outside app
  see https://developer.4d.com/docs/API/DataStoreClass/#open-datastore
*/

#DECLARE($AMS_REST_ADDRESS : Text)->$ams_ds : cs:C1710.DataStore

$AMS_REST_ADDRESS:=(Count parameters:C259=1) ? $AMS_REST_ADDRESS : "192.168.1.72:8080"  //production
//$AMS_REST_ADDRESS:="10.0.0.152:8080"  //home network

var $connectTo : Object
var $localId : Text

$connectTo:=New object:C1471("type"; "4D Server"; "hostname"; $AMS_REST_ADDRESS)
//$connectTo:=New object("type"; "4D Server"; "hostname"; WMS_TEST_SERVER_URL)  //"10.0.0.152:8080")

$localId:="ams"

//ON ERR CALL("e_file_io_error")

$ams_ds:=Open datastore:C1452($connectTo; $localId)

//ON ERR CALL("")

If ($ams_ds=Null:C1517) || (OB Keys:C1719($ams_ds)[0]#"Addresses")  //return
	//Confirm("Could not connect to aMs database."; "OK"; "Help")
End if 

return $ams_ds
