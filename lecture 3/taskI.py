from math import log2

def hemming_encode(s: str)->str:
    help_bits_quantity = 0
    i = 0
    counter = 0
    code_list = [0]
    for le in s:
        code_list.append(int(le))

    while(i + help_bits_quantity <= len(s)+2**int(log2(len(s)))-1):
        if(i == 2**help_bits_quantity):
            code_list.insert(i, 0)
            help_bits_quantity += 1
        i += 1
    total_length = help_bits_quantity + len(s)

    for j in range(help_bits_quantity):
        counter = 0
        for k in range(2**j, total_length + 1, 2**(j + 1)):
            for r in range(k, min(k + 2**j, total_length + 1)):
                if(code_list[r] == 1):
                    counter+= 1
        if(counter % 2 == 1):
            code_list[2**j] = 1
    code_list.pop(0)
    return ''.join(map(str, code_list))


def hemming_decode(s: str) -> str:
    code_list = [int(c) for c in s]
    answer = ""
    mistakes = []
    i = 0
    control_bits = 0
    while((2 ** control_bits) <= len(s)):
        control_bits += 1
    for i in range(control_bits):
        counter = 0
        control_bit_position = 2 ** i
        for j in range(1, len(s) + 1):
            if(j & control_bit_position)!= 0:
                if(code_list[j - 1] == 1):
                    counter += 1
        if(counter % 2 != code_list[control_bit_position - 1]):
            mistakes.append(control_bit_position)
    if(mistakes):
        error_pos = sum(mistakes) - 1
        if(0 <= error_pos and error_pos < len(code_list)):
            code_list[error_pos] ^= 1
    for j in range(1, len(code_list) + 1):
        if((j & (j - 1)) != 0):
            answer += str(code_list[j - 1])
    return answer

x = input()
print(hemming_encode(x))
y = input()
print(hemming_decode(y))