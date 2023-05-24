
class Account
{
    public string AccountNumber { get; }
    public string AccountHolderName { get; set; }
    public decimal AccountBalance { get; protected set; }

    public Account(string accountNumber, string accountHolderName, decimal accountBalance)
    {
        AccountNumber = accountNumber;
        AccountHolderName = accountHolderName;
        AccountBalance = accountBalance;
    }

    public virtual void Deposit(decimal amount)
    {
        AccountBalance += amount;
        Console.WriteLine($"Deposited {amount:C} into account {AccountNumber}. New balance is {AccountBalance:C}.");
    }

    public virtual void Withdraw(decimal amount)
    {
        if (amount > AccountBalance)
        {
            Console.WriteLine($"Insufficient funds in account {AccountNumber}. Withdrawal failed.");
        }
        else
        {
            AccountBalance -= amount;
            Console.WriteLine($"Withdrew {amount:C} from account {AccountNumber}. New balance is {AccountBalance:C}.");
        }
    }

    public virtual void Transfer(Account destination, decimal amount)
    {
        if (amount > AccountBalance)
        {
            Console.WriteLine($"Insufficient funds in account {AccountNumber}. Transfer failed.");
        }
        else
        {
            Withdraw(amount);
            destination.Deposit(amount);
            Console.WriteLine($"Transferred {amount:C} from account {AccountNumber} to account {destination.AccountNumber}.");
        }
    }
}

class SavingsAccount : Account
{
    public decimal InterestRate { get; }

    public SavingsAccount(string accountNumber, string accountHolderName, decimal accountBalance, decimal interestRate)
        : base(accountNumber, accountHolderName, accountBalance)
    {
        InterestRate = interestRate;
    }

    public void CalculateInterest()
    {
        decimal interest = AccountBalance * InterestRate;
        Deposit(interest);
        Console.WriteLine($"Calculated interest on account {AccountNumber}. New balance is {AccountBalance:C}.");
    }
}

class CheckingAccount : Account
{
    public decimal MonthlyFee { get; }

    public CheckingAccount(string accountNumber, string accountHolderName, decimal accountBalance, decimal monthlyFee)
        : base(accountNumber, accountHolderName, accountBalance)
    {
        MonthlyFee = monthlyFee;
    }

    public void DeductMonthlyFee()
    {
        Withdraw(MonthlyFee);
        Console.WriteLine($"Deducted monthly fee of {MonthlyFee:C} from account {AccountNumber}. New balance is {AccountBalance:C}.");
    }
}

class InvestmentAccount : Account
{
    public List<string> Investments { get; }

    public InvestmentAccount(string accountNumber, string accountHolderName, decimal accountBalance, List<string> investments)
        : base(accountNumber, accountHolderName, accountBalance)
    {
        Investments = investments;
    }

    public void AddInvestment(string investment)
    {
        Investments.Add(investment);
        Console.WriteLine($"Added investment {investment} to account {AccountNumber}.");
    }

    public void RemoveInvestment(string investment)
    {
        Investments.Remove(investment);
        Console.WriteLine($"Removed investment {investment} from account {AccountNumber}.");
    }
}