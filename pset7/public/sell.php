<?php

    // configuration
    require("../includes/config.php");
    
     if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        render("sell_form.php", ["title" => "Buy"]);
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $stock = lookup($_POST["symbol"]);
        
        // determine how many stocks user owns
        $howMany = CS50::query("SELECT shares FROM stocks WHERE user_id = '$_SESSION[id]' AND symbol = '$stock[symbol]'");
        $howMany = array_pop($howMany);
        $howMany = $howMany["shares"];
        
        // remove stock from database
        $sell = CS50::query("DELETE FROM stocks WHERE user_id = '$_SESSION[id]' AND symbol = '$stock[symbol]'");
        
        $priceOfStocks = $howMany * $stock["price"];
        
        // update cash
        $cash = CS50::query("UPDATE users SET cash = cash + $priceOfStocks WHERE id = '$_SESSION[id]'");
        
        // update history
        $history = CS50::query("INSERT INTO history (user_id, action, symbol, shares, price) VALUES ('$_SESSION[id]', 'SELL', '$stock[symbol]', '$howMany', '$priceOfStocks')");
        
        // redirect to the portfolio
        header("Location: index.php");
    }
    
?>