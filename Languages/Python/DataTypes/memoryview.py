
byte_arr = bytearray('xyzabc', 'utf-8')

mv_obj = memoryview(byte_arr)
print(bytes(mv_obj))

mv_to_str = str(mv_obj)
print(type(mv_to_str), mv_to_str)

# for byte in mv_obj:
#     print(byte, bytes(byte))