def merge_sort(orders):
    if len(orders) > 1:
        mid = len(orders) // 2

        left = orders[:mid]
        right = orders[mid:]

        merge_sort(left)
        merge_sort(right)

        i = 0
        j = 0
        k = 0

        # Compare delivery times
        while i < len(left) and j < len(right):
            if left[i][1] <= right[j][1]:
                orders[k] = left[i]
                i += 1
            else:
                orders[k] = right[j]
                j += 1
            k += 1

        # Copy remaining elements from left
        while i < len(left):
            orders[k] = left[i]
            i += 1
            k += 1

        # Copy remaining elements from right
        while j < len(right):
            orders[k] = right[j]
            j += 1
            k += 1


# Online orders: (Order ID, Delivery Time in minutes)
orders = [
    ("O101", 45),
    ("O102", 20),
    ("O103", 35),
    ("O104", 15),
    ("O105", 50),
    ("O106", 30)
]

print("Original Orders:")
for order in orders:
    print(order[0], "-", order[1], "minutes")

merge_sort(orders)

print("\nOrders Sorted by Delivery Time:")
for order in orders:
    print(order[0], "-", order[1], "minutes")
