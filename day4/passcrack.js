const min = 158126;
const max = 624574;

const crackcode = (num) => {
	let double = false;
	let double_count = 0;


	while (num > 0)
	{
		// get current digit 
		let digit = num % 10;
		// move on digit to the left.
		num = Math.floor(num / 10);
		// check for digit decrease in sequence
		if (digit < num % 10)
			return (0);
		// try and find double digit 
		if (digit == num % 10)
			double_count++;
		else
		{
			if (double_count == 1)
				double = true;
			double_count = 0;
		}
	}

	if (!double)
		return (0);
	return (1);
};

if (process.argv[2])
	console.log(crackcode(process.argv[2]));
else
{
	let i = min;
	let numof = 0;
	while (i <= max)
		numof += crackcode(i++);

	console.log(numof);
}
