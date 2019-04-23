<?php
$xmldoc = new DomDocument( '1.0' );
$xmldoc->preserveWhiteSpace = false;
$xmldoc->formatOutput = true;

$name = $_POST['username'];
$pass = $_POST['password'];
$mobile = $_POST['mobile'];
$email = $_POST['email'];
$age = $_POST['age'];

if( $xml = file_get_contents( 'database.xml') ) {
    $xmldoc->loadXML( $xml, LIBXML_NOBLANKS );

    // find the headercontent tag
    $root = $xmldoc->getElementsByTagName('profile')->item(0);

    // create the <product> tag
    $account = $xmldoc->createElement('account');
    

    // add the product tag before the first element in the <headercontent> tag
    $root->insertBefore( $account, $root->lastChild );

    // create other elements and add it to the <product> tag.
    $nameElement = $xmldoc->createElement('name');
    $account->appendChild($nameElement);
    $nameText = $xmldoc->createTextNode($name);
    $nameElement->appendChild($nameText);

    $passElement = $xmldoc->createElement('pass');
    $account->appendChild($passElement);
    $passText = $xmldoc->createTextNode($pass);
    $passElement->appendChild($passText);

    $emailElement = $xmldoc->createElement('email');
    $account->appendChild($emailElement);
    $emailText = $xmldoc->createTextNode($email);
    $emailElement->appendChild($emailText);
	
	$mobileElement = $xmldoc->createElement('mobile');
    $account->appendChild($mobileElement);
    $mobileText = $xmldoc->createTextNode($mobile);
    $mobileElement->appendChild($mobileText);
		
	$ageElement = $xmldoc->createElement('age');
    $account->appendChild($ageElement);
    $ageText = $xmldoc->createTextNode($age);
    $ageElement->appendChild($ageText);
    
	
	$xmldoc->save('database.xml');
}
?>

<html>
<body>
<h2>You are Successfully Register please<a href="login.html">go to Login page</a></h2>
</body>
</html>