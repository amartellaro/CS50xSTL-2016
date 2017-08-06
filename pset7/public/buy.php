<?php

    // configuration
    require("../includes/config.php"); 
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("buy_form.php", ["title" => "Buy"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        
        $stock = lookup($_POST["symbol"]);
        $shares = (int)$_POST["shares"];
        
        // validation
        if($stock == NULL)
            apologize("Please select a valid stock option.");
            
        if($shares == NULL)
            apologize("Please select a valid number of shares.");
            
        if ($shares < 0)
            apologize("Please select a positive number of shares.");
        
        // check that user can afford stock
        $cashOnHand = CS50::query("SELECT * FROM users WHERE id = '$_SESSION[id]'");
        $cashOnHand = array_pop($cashOnHand);
        $cashOnHand = $cashOnHand["cash"];
        
        $wantToBuy = ($stock["price"] * $shares);
        
        if ($wantToBuy > $cashOnHand)
        {
           apologize ("You can't afford that!");
        }
        
        // check if user already owns some of that particular stock
        $alreadyOwn = CS50::query("SELECT shares FROM stocks WHERE user_id = '$_SESSION[id]' AND symbol = '$stock[symbol]'");
        $alreadyOwn = array_pop($alreadyOwn);
        $alreadyOwn = $alreadyOwn["shares"];

        // if we don't already own some of this stock
        if($alreadyOwn == NULL)
        {
            $buy = CS50::query("INSERT INTO stocks (user_id, symbol, shares) VALUES ('$_SESSION[id]', '$stock[symbol]', '$shares')");
        }
        // if we do already own some of this stock
        else
        {
            $buy = CS50::query("UPDATE stocks SET shares = $shares + $alreadyOwn WHERE user_id = '$_SESSION[id]' AND symbol = '$stock[symbol]'"); 
        }
        
        // update cash
        $cash = CS50::query("UPDATE users SET cash = cash - $wantToBuy WHERE id = '$_SESSION[id]'");
        
        // update history
        $history = CS50::query("INSERT INTO history (user_id, action, symbol, shares, price) VALUES ('$_SESSION[id]', 'BUY', '$stock[symbol]', '$shares', '$wantToBuy')");
        
        // redirect to the portfolio
        header("Location: index.php");
    }
    
?>