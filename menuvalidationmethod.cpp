int validation()
{
	int n; std::cin >> n;
	bool valid = false;
	while (!valid)
	{
		if (n<=5 && n>=1)
		{
			valid = true;
		}
		else
		{
			if (!std::cin) //prevents char from breaking code
			{
				std::cin.clear();
				std::cin.ignore();
				/*With multiple char the err message repeats
				But will still run code*/
			}
			std::cout << "\n Please input a valid option: ";
			std::cin >> n;
		}
	}
	return n;
}
