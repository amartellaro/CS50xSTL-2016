<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("funds_form.php", ["title" => "Add Funds"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $amount = $_POST["amount"];

        if(is_numeric($amount) && $amount > 0)
        {
            // update cash
            $addFunds = CS50::query("UPDATE users SET cash = cash + $amount WHERE id = '$_SESSION[id]'");
        
            // redirect to the portfolio
            header("Location: index.php");
        }
        else
            apologize("Please insert a valid amount.");
        
    }    
    
?>
