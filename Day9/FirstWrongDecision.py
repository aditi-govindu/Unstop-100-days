# Enter your code here. Read input from STDIN. Print output to STDOUT
'''
Description: Kala is the director of an engineering college. He makes the decision for college based on the previous decision. Unfortunately, the latest decision of Kala for college is wrong. Since each decision for college is based on the previous decision, all the decisions after a wrong decision are also wrong. Kala is worried about the wrong decision. So, he wants to find out the first wrong decision, which causes all the following decisions to be wrong.

Kala needs your help to find out the answer. Print -1 if there is no wrong decision.
'''

decisions = input()
print(decisions.find('W'))