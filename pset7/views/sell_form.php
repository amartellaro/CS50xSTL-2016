<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select name="symbol" class="form-control">
            <option disabled selected value="">Symbol</option>

            <?php
            $stocks = CS50::query("SELECT symbol FROM stocks WHERE user_id = '$_SESSION[id]'");
                
            foreach ($stocks as $stock)
            {
                echo("<option value='{$stock['symbol']}'>"); 
                echo $stock['symbol'];
                echo("</option>"); 
            } ?>
            </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>
