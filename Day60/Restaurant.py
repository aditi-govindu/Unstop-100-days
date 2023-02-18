# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: There is a restaurant having n tables numbered from ( 0  to n-1 ). A person booked the whole restaurant for his birthday party. It’s the time for billing. Now, the person asked the restaurant owner to show all the orders from every table i.e. 0 to n-1.

There is a total of m order placed in the party. Your task is to print the orders of the i-th table. The orders of the ith table must be sorted in ascending order.

Note - There is at least one order from each table and no order is repeated from one table.
'''

from collections import defaultdict

# User input
tables, orders = map(int, input().split())
table_ord = defaultdict(list)

for i in range(orders):
    data = input().split()
    # Store hashmap of table versus orders
    table_ord[data[0]].append(data[1])

for order in table_ord.values():
    # Sort in ascending order and display results
    order.sort()
    for o in order:
        print(o, end = ' ')
    print()