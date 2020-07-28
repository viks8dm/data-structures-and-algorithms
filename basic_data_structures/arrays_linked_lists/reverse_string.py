"""
given a string reverse it
"""

def reverse_string(my_string):
  """
  Reverse the input string

  Args:
     my_string(string): String to be reversed
  Returns:
     string: The reversed string
  """
  rev_str = ""
  n = len(my_string)
  for i in range(len(my_string)):
    rev_str += my_string[n-i-1]
    
  return rev_str

# test cases
print ("Pass" if ('retaw' == string_reverser('water')) else "Fail")
print ("Pass" if ('!noitalupinam gnirts gnicitcarP' == string_reverser('Practicing string manipulation!')) else "Fail")
print ("Pass" if ('3432 :si edoc esuoh ehT' == string_reverser('The house code is: 2343')) else "Fail")
