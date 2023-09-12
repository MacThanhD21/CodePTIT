if __name__ == "__main__":
    n = int(input())  # Số lượng giám khảo
    scores = set(list(map(float, input().split())))  # Điểm của từng giám khảo
    
    min_score = min(scores)
    max_score = max(scores)
    
    # 
    scores.remove(min_score)
    scores.remove(max_score)
    
    print(scores)
    
    average_score = sum(scores) / len(scores)
    
    print("{:.2f}".format(average_score))