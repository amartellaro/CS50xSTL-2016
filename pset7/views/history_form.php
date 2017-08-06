<table class="table table-striped">

    <thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Shares</th>
            <th>Price</th>
        </tr>
    </thead>
    
    <tbody>
        
    <?php
    // query transactions from table
    $transactions = CS50::query("SELECT * FROM history WHERE user_id = '$_SESSION[id]'");
    
    foreach($transactions as $transaction)
    {
        echo("<tr><td align='left'>" . $transaction["action"] . "</td><td align='left'>" . $transaction["time"] . 
        "</td><td align='left'>" . $transaction["symbol"] . "</td><td align='left'>" . $transaction["shares"] . "</td><td align='left'>" . $transaction["price"] . "</td></tr>");
    }
    
    ?>
        
    </tbody>

</table>