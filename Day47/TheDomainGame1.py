# Enter your code here. Read input from STDIN. Print output to STDOUT
n = int(input())
visits = {}

for i in range(n):
    data = input().split()
    count = int(data[0])

    domains = data[1].split('.')
    visits[data[1]] = count

    if len(domains) == 3:
        key1 = domains[1] + '.' + domains[2]
        key2 = domains[2]

        if key1 in visits:
            visits[key1] += count
        else:
            visits[key1] = count

        if key2 in visits:
            visits[key2] += count
        else:
            visits[key2] = count 

    else:
        key2 = domains[1]

        if key2 in visits:
            visits[key2] += count
        else:
            visits[key2] = count 

# First sort dicitonary based on URL values
sortedVisits2 = dict(sorted(visits.items(), key = lambda x:x[0]))
# Then sort dicitonary based on count of visits (value)
sortedVisits = dict(sorted(sortedVisits2.items(), key = lambda x:x[1]))

result = '['
for k, v in sortedVisits.items():
    result += str(v) + ' ' + k + ', '

result = result.rstrip(', ')
result += ']'
print(result)