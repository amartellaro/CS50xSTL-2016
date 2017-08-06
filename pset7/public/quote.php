<?php

    // configuration
    require("../includes/config.php"); 

    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("quote_form.php", ["title" => "Get Quote"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        render("quote.php", ["title" => "Quote"]);
    }

?>
