const fs = require('fs');

function calcModuleFuel(mass)
{
	const fuel = Math.floor(mass / 3) - 2;
	if (fuel <= 0)
		return (0);
	return (fuel + calcModuleFuel(fuel));
}

fs.readFile('input.txt', 'utf8', (err, res) => {
	const sum = res.split('\n').map(n => Number(n))
		.reduce((s,n) => {
			return (s + calcModuleFuel(n));
		}, 0);
	console.log('sum', sum);
});
