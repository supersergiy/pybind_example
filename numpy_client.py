import numpy_example
import numpy as np


if __name__ == '__main__':
    xs = np.arange(12).reshape(3,4).astype('float')
    print(xs)
    print("np :", xs.sum())
    print("cpp:", numpy_example.sum(xs))

    print()
    numpy_example.twice(xs)
    print(xs)
