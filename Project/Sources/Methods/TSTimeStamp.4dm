//%attributes = {}
//Procedure: TSTimeStamp({theDate};{theTime})  073196  MLB
//convert date and time to longint  see TN 29
//see (P) TS2DateTime for conversion back
//this will fail in May of 2063, wont be my problem

#DECLARE($date : Date; $time : Time)->$timestamp_i

var $pc : Integer

$pc:=Count parameters:C259

Case of 
	: ($pc=0)
		$date:=Current date:C33
		$time:=Current time:C178
		
	: ($pc=1)
		If ($date=!00-00-00!)
			$date:=!1995-04-17!  // my date of hire
		Else 
			$date:=$date
		End if 
		$time:=Current time:C178
		
	: ($pc=2)
		If ($date=!00-00-00!)
			$date:=!1995-04-17!
		End if 
		$time:=$2
		
End case 

$timestamp_i:=(($date-!1995-04-17!)*86400)+($time*1)  //24*60*60

return $timestamp_i
