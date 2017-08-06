<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    
    // Get geographic info
    $geo = $_GET["geo"];
    
    // Split geographic info into array
    $geoArray = preg_split("/[^a-zA-Z\d]/", $geo, -1, PREG_SPLIT_NO_EMPTY); 
    
    // Count # of elements in the array
    $geoCount = count($geoArray);
    
    // If there's only one element
    if ($geoCount == 1)
    {
        // Check if it's a zip code
        if((is_numeric($geo)) && (strlen($geo) == 5))
        {
    	    $places = CS50::query("SELECT * FROM places WHERE postal_code = ?", $geo);
        }
        // Check if it's a state abbreviation
        else if(strlen($geo) == 2)
    	{
    		$places = CS50::query("SELECT * FROM places WHERE admin_code1 = ?", strtoupper($geo));
    	}
    	// Check if it's a city
    	else
    	{
    		$places = CS50::query("SELECT * FROM places WHERE place_name LIKE ?", $geo);
    	}
    	
    	// If it's not a city, check if it's a state
    	if(empty($places))
    	{
    		$places = CS50::query("SELECT * FROM places WHERE admin_name1 LIKE ?", $geo);
    	}
    }
    else if($geoCount > 1)
    {
    	// Search across multiple columns
    	$places = CS50::query("SELECT * FROM places WHERE MATCH(place_name, admin_name1, admin_code1) AGAINST (?)", $geo);
    }
    else
    {
        // Throw an error if there is no input
        echo ("What would you like to search for?\n");
    }

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>