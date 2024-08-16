import hashlib

class BloomFilter:
    def __init__(self, size, num_hashes):
        self.size = size
        self.num_hashes = num_hashes
        self.bit_array = [0] * size
    
    def _hashes(self, item):
        """Generate k hash values for the item."""
        results = []
        for i in range(self.num_hashes):
            # Create a hash value based on the item and hash index
            result = int(hashlib.md5((item + str(i)).encode('utf-8')).hexdigest(), 16) % self.size
            results.append(result)
        return results
    
    def add(self, item):
        """Add an item to the Bloom filter."""
        for hash_val in self._hashes(item):
            self.bit_array[hash_val] = 1
    
    def check(self, item):
        """Check if an item is in the Bloom filter."""
        for hash_val in self._hashes(item):
            if self.bit_array[hash_val] == 0:
                return False
        return True

# Example usage
if __name__ == "__main__":
    # Initialize Bloom filter with size 100 and 3 hash functions
    bloom_filter = BloomFilter(size=100, num_hashes=3)
    
    # Add some items
    bloom_filter.add("dog")
    bloom_filter.add("cat")
    
    # Check for items
    print("Checking for 'dog':", bloom_filter.check("dog"))  # Likely True
    print("Checking for 'cat':", bloom_filter.check("cat"))  # Likely True
    print("Checking for 'fish':", bloom_filter.check("fish"))  # Likely False
