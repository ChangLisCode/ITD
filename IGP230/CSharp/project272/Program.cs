// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");
using System;
using System.Collections.Generic;

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

class Program
{
    static void Main(string[] args)
    {
        List<Account> accounts = new List<Account>();

        bool exit = false;
        while (!exit)
        {
            // Console.WriteLine(" ");
            // Console.WriteLine("---------------------------------------------------------------- ");
            Console.WriteLine("Welcome to ITD bank system, Please choose what I can do for you: ");
            // Console.WriteLine("---------------------------------------------------------------- ");
            // Console.WriteLine(" ");

            Console.WriteLine("1. Create new account");
            Console.WriteLine("2. Deposit money");
            Console.WriteLine("3. Withdraw money");
            Console.WriteLine("4. Transfer funds");
            Console.WriteLine("5. Calculate interest");
            Console.WriteLine("6. Deduct monthly fee");
            Console.WriteLine("7. Add investment");
            Console.WriteLine("8. Remove investment");
            Console.WriteLine("9. Exit");
            Console.WriteLine(" ");


            Console.Write("Enter your choice: ");
            int choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    CreateAccount(accounts);
                    break;
                case 2:
                    DepositMoney(accounts);
                    break;
                case 3:
                    WithdrawMoney(accounts);
                    break;
                case 4:
                    TransferFunds(accounts);
                    break;
                case 5:
                    CalculateInterest(accounts);
                    break;
                case 6:
                    DeductMonthlyFee(accounts);
                    break;
                case 7:
                    AddInvestment(accounts);
                    break;
                case 8:
                    RemoveInvestment(accounts);
                    break;
                case 9:
                    exit = true;
                    break;
                default:
                    Console.WriteLine("Invalid choice. Please try again.");
                    break;
            }
        }
    }

    static void CreateAccount(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();
        Console.Write("Enter account holder name: ");
        string? accountHolderName = Console.ReadLine();
        Console.Write("Enter initial account balance: ");
        decimal accountBalance = decimal.Parse(Console.ReadLine());
        
        // Console.WriteLine(" ");
        // Console.WriteLine("---------------------------------------------------------------- ");
        Console.WriteLine("Select account type:");
        Console.WriteLine("1. Savings Account");
        Console.WriteLine("2. Checking Account");
        Console.WriteLine("3. Investment Account");
        // Console.WriteLine("---------------------------------------------------------------- ");
        // Console.WriteLine(" ");
        
        Console.Write("Enter your choice: ");
        int accountTypeChoice = int.Parse(Console.ReadLine());

        Account account;
        switch (accountTypeChoice)
        {
            case 1:
                Console.Write("Enter interest rate: ");
                decimal interestRate = decimal.Parse(Console.ReadLine());
                account = new SavingsAccount(accountNumber, accountHolderName, accountBalance, interestRate);
                break;
            case 2:
                Console.Write("Enter monthly fee: ");
                decimal monthlyFee = decimal.Parse(Console.ReadLine());
                account = new CheckingAccount(accountNumber, accountHolderName, accountBalance, monthlyFee);
                break;
            case 3:
                Console.Write("Enter investment count: ");
                int investmentCount = int.Parse(Console.ReadLine());
                List<string> investments = new List<string>();
                for (int i = 0; i < investmentCount; i++)
                {
                    Console.Write($"Enter investment {i + 1}: ");
                    string? investment = Console.ReadLine();
                    investments.Add(investment);
                }
                account = new InvestmentAccount(accountNumber, accountHolderName, accountBalance, investments);
                break;
            default:
                Console.WriteLine("Invalid account type. Account creation failed.");
                return;
        }

        accounts.Add(account);
        Console.WriteLine("Account created successfully.");
    }

    static void DepositMoney(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();
        Console.Write("Enter deposit amount: ");
        decimal amount = decimal.Parse(Console.ReadLine());

        Account account = FindAccount(accounts, accountNumber);
        if (account != null)
        {
            account.Deposit(amount);
        }
    }

    static void WithdrawMoney(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();
        Console.Write("Enter withdrawal amount: ");
        decimal amount = decimal.Parse(Console.ReadLine());

        Account account = FindAccount(accounts,accountNumber);

        if (account != null)
        {
        account.Withdraw(amount);
        }
    }
    static void TransferFunds(List<Account> accounts)
    {
        Console.Write("Enter source account number: ");
        string? sourceAccountNumber = Console.ReadLine();
        Console.Write("Enter destination account number: ");
        string? destinationAccountNumber = Console.ReadLine();
        Console.Write("Enter transfer amount: ");
        decimal amount = decimal.Parse(Console.ReadLine());

        Account sourceAccount = FindAccount(accounts, sourceAccountNumber);
        Account destinationAccount = FindAccount(accounts, destinationAccountNumber);

        if (sourceAccount != null && destinationAccount != null)
        {
            sourceAccount.Transfer(destinationAccount, amount);
        }
    }

    static void CalculateInterest(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string accountNumber = Console.ReadLine();

        SavingsAccount account = FindAccount(accounts, accountNumber) as SavingsAccount;
        if (account != null)
        {
            account.CalculateInterest();
        }
        else
        {
            Console.WriteLine("Account not found or is not a savings account.");
        }
    }

    static void DeductMonthlyFee(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();

        CheckingAccount account = FindAccount(accounts, accountNumber) as CheckingAccount;
        if (account != null)
        {
            account.DeductMonthlyFee();
        }
        else
        {
            Console.WriteLine("Account not found or is not a checking account.");
        }
    }

    static void AddInvestment(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();

        InvestmentAccount account = FindAccount(accounts, accountNumber) as InvestmentAccount;
        if (account != null)
        {
            Console.Write("Enter investment to add: ");
            string? investment = Console.ReadLine();
            account.AddInvestment(investment);
        }
        else
        {
            Console.WriteLine("Account not found or is not an investment account.");
        }
    }

    static void RemoveInvestment(List<Account> accounts)
    {
        Console.Write("Enter account number: ");
        string? accountNumber = Console.ReadLine();

        InvestmentAccount account = FindAccount(accounts, accountNumber) as InvestmentAccount;
        if (account != null)
        {
            Console.Write("Enter investment to remove: ");
            string? investment = Console.ReadLine();
            account.RemoveInvestment(investment);
        }
        else
        {
            Console.WriteLine("Account not found or is not an investment account.");
        }
    }

    static Account FindAccount(List<Account> accounts, string accountNumber)
    {
        return accounts.Find(account => account.AccountNumber == accountNumber);
    }
}

