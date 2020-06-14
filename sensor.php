<?php

class status{
	public $link='';
  function __construct($VALUE){
	$this->connect();
	$this->storeInDB($VALUE);
}

function connect(){
	$this->link = mysqli_connect('localhost','root','') or die('Cannot connect to the Database');
	mysqli_select_db($this->link,'trial0') or die('Cannot select the Database');
}

function storeInDB($VALUE){
	$query = "insert into status set value='".$VALUE."'";
	$result = mysqli_query($this->link,$query) or die('Errant query:  '.$query);
}
}

if(isset($_GET['VALUE'])){
	$status=new status($_GET['VALUE']);
}

?>