<?php
/*
 * Created on Sep 12, 2007
 *
 * To change the template for this generated file go to
 * Window - Preferences - PHPeclipse - PHP - Code Templates
 */

ini_set('url_rewriter.tags', '');

$method = $_SERVER['REQUEST_METHOD'];
$ll_data=NULL;
switch($method) {
    case 'GET':  $ll_data = $_GET;  break;
    case 'POST': $ll_data = $_POST; break;
}

foreach ($ll_data as $field => $value) {

  
  if (is_array($value)){
  	
    $safeArray=Array();
    foreach($value as $k => $v){
    	$v=makeSafe($v);
    	$safeArray[$k]=$v;
    }
    $value=$safeArray;	
  } else {
    $value=makeSafe($value);
  }
  			     
  $ll_data[$field]=$value;
  
}

function makeSafe($value) {
	 
  $value = stripslashes($value);
  $value = htmlspecialchars($value);
  $value = strtr($value, array('(' => '&#40;', ')' => '&#41;'));	
  $value = utf8_decode($value);
  $value = strip_tags($value);
  $value = strtr($value, array(
  								'`' => '',
  								'$' => '',
  								'^' => '',
  								'%' => '',
  								'*' => '',
  								'=' => '',
  								'+' => '',
  								'[' => '',
  								']' => '',
  								'{' => '',
  								'}' => '',
  								';' => '',
  								':' => '',
  								'#' => '',
  								'~' => '',
  								'<' => '',
  								'>' => '',
  								'\\' => '',
  								'?' => '',
  								'|' => '',
  								'\"' => '',
  								'\'' => '',
  								'£' => '',
  								'\r\n' => '',
  								'\n' => '',
  								'\t' => '',
  								)
  			     );
  return $value;
}

function passRequestInForm(){
	global $ll_data;

    
    $hiddenFieldStr="";
    if (count($ll_data) > 0) {
      foreach ($ll_data as $name => $value) {
      	$hiddenFieldStr .= "<input type=\"hidden\" name=\"$name\" value=\"$value\">\n";
      }     
    }  
    
    return $hiddenFieldStr;
      
}

?>
