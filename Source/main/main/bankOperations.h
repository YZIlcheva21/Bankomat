#pragma once

//Displays the user's current balance
void balance();

//Facilitates money transactions, allowing the user to send money to a recipient
void transactions();

//Updates the user's balance by adding or subtracting the specified amount
void updateBalance(int& balance, int amount);

//Allows the user to specify a will, leaving a designated amount for a specified inheritor
void will();