import os
import argparse

parser = argparse.ArgumentParser(description="ric diff, differ two files.")
parser.add_argument("left_file", help="left file to compare")
parser.add_argument("right_file", help="right file to compare")
args = parser.parse_args()

if not os.path.isfile(args.left_file):
    raise FileNotFoundError(f"This file not found {args.left_file}")
elif not os.path.isfile(args.right_file):
    raise FileNotFoundError(f"This file not found {args.right_file}")
elif args.left_file == args.right_file:
    raise NameError(f"The arg you inserted are the same.")
else:
    pass

# with open(args.left_file, "r") as left_file, open(args.right_file, "r") as right_file:
#     print(f'you choosed {left_file.read()} and {right_file.read()}')
#     print(f"{hash(left_file.read()) = } --- { hash(right_file.read()) = }")
#     if hash(left_file.read()) == hash(right_file.read()):
#         raise ValueError('Files has the same hash.')

# def binit(file_open):
#     full_string = ''
#     for char in file_open.read():
#         full_string += format(char, 'b')
#     return full_string
#
def bit_wise_diff(left, right):
    diffs = ''
    while left:
        print(f"{ord(left[-2])} {ord(left[-2]):b} \t{ord(right[-2])} {ord(right[-2]):b}")
        diffs += (ord(left[-2]) & ord(right[-2]))
        left >>= 1
        right >>= 1
    return diffs


with open(args.left_file, "rb") as left_file, open(args.right_file, "rb") as right_file:
    diff = bit_wise_diff(left_file.read(), right_file.read())
    print(diff)
#     print(f"{binit(left_file)}")
# print(f"{open(args.right_file, 'rb').read()}")


