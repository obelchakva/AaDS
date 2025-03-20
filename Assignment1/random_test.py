import random
import string
from base64 import b85encode, b85decode

def generate_random_data(length):
    return ''.join(random.choice(string.printable) for _ in range(length))

def test_ascii85_encoding():
    data = generate_random_data(100)
    encoded_with_base64 = b85encode(data.encode()).decode()
    encoded_with_custom = encodeAscii85(data.encode())
    
    assert encoded_with_base64 == encoded_with_custom, f"Encoded output mismatch: Expected {encoded_with_base64}, got {encoded_with_custom}"

def test_ascii85_decoding():
    encoded_data = b85encode(generate_random_data(100).encode()).decode()
    decoded_with_base64 = b85decode(encoded_data.encode()).decode()
    decoded_with_custom = decodeAscii85(encoded_data).decode()
    
    assert decoded_with_base64 == decoded_with_custom, f"Decoded output mismatch: Expected {decoded_with_base64}, got {decoded_with_custom}"

if __name__ == "__main__":
    test_ascii85_encoding()
    test_ascii85_decoding()
