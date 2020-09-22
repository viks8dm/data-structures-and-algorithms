# Roman numerals to Integer

Given Roman numeral as input, convert it to an integer.

Roman numeral symbols:

|  Symbol  |  Value  |
|----------|---------|
|  I  |  1  |
|  V  |  5  |
|  X  |  10  |
|  L  |  50  |
|  C  |  100  |
|  D  |  500  |
|  M  |  1000  |


### Notes:

* Roman numerals are usually written largest to smallest from left to right.
* There are six instances where subtraction is used:
	* I can be placed before V (5) and X (10) to make 4 and 9. 
	* X can be placed before L (50) and C (100) to make 40 and 90. 
	* C can be placed before D (500) and M (1000) to make 400 and 900.


### Examples:

1.
```
Input: "III"
Output: 3
```

2. 
```
Input: "IV"
Output: 4
```

3. 
```
Input: "IX"
Output: 9
```

4. 
```
Input: "LVIII"
Output: 58
```

5. 
```Input: "MCMXCIV"
Output: 1994
```
