//%attributes = {}
/*
 Method: AMS_SaveInboxMsg   ( ) ->
 By: MelvinBohince @ 07/05/24, 21:10:04
 Description:
  

 Example Use:
  
*/

#DECLARE($inbox_pkid : Integer; $ams_ds : Object)->$success : Boolean  //$ams_ds : cs.DataStore gives compiler warning

var $TESTING : Boolean
var $NEEDS_MAPPED : Integer
var $local_e : cs:C1710.Web_InboxEntity
var $status_o : Object
var $ams_e; $unique_e : Object  //of ams type cs.edi_InboxEntity

$success:=False:C215

$ams_ds:=(Count parameters:C259=2) ? $ams_ds : aMs_Open_RemoteDataStore
If ($ams_ds=Null:C1517)
	return $success
End if 

//todo:owc turn off testing
$TESTING:=True:C214
$NEEDS_MAPPED:=$TESTING ? -222 : 0

//save local to server 

$ams_e:=$ams_ds.edi_Inbox.new()
If ($ams_e=Null:C1517)
	return $success  //wtf
End if 

//mirror the local to the remote
$local_e:=ds:C1482.Web_Inbox.get($inbox_pkid)
If ($local_e=Null:C1517)  //wtf, thats how we got here
	$success:=False:C215
	return $success
End if 

$unique_e:=$ams_ds.edi_Inbox.query("ID = :1"; $local_e.ID).first()
If (Not:C34($local_e=Null:C1517))  //id already in use in ams
	$success:=False:C215
	return $success
End if 

$ams_e.ID:=$local_e.ID

//convert utc to local
$ams_e.Received:=TSTimeStamp(Date:C102($local_e.Received_UTC); Time:C179($local_e.Received_UTC))
$ams_e.Date_Received:=Date:C102($local_e.Received_UTC)

$ams_e.Path:=$local_e.Received_UTC  //path is a useless legacy field
$ams_e.Content_Text:=$local_e.Content_Text
$ams_e.Mapped:=$NEEDS_MAPPED  //ams will do these in a batch

$status_o:=$ams_e.save()
If ($status_o.success)
	//tag the local
	$local_e.SentToAMS_UTC:=Timestamp:C1445
	$status_o:=$local_e.save()
End if   //remote copy saved

$success:=$status_o.success
