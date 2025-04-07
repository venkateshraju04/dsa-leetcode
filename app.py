import os
import random
import subprocess
from datetime import datetime, timedelta

def generate_random_datetime(start, end):
    delta = end - start
    random_seconds = random.randint(0, int(delta.total_seconds()))
    return start + timedelta(seconds=random_seconds)

def make_commit_at_time(commit_time, commit_message="Random commit"):
    date_str = commit_time.strftime("%Y-%m-%dT%H:%M:%S")
    env = os.environ.copy()
    env["GIT_AUTHOR_DATE"] = date_str
    env["GIT_COMMITTER_DATE"] = date_str

    with open("temp_file.txt", "a") as f:
        f.write(f"{date_str}\n")

    subprocess.run(["git", "add", "temp_file.txt"], check=True)
    subprocess.run(["git", "commit", "-m", commit_message], check=True, env=env)

def main():
    start_date = datetime.strptime("2025-01-01", "%Y-%m-%d")
    end_date = datetime.strptime("2025-04-21", "%Y-%m-%d")

    num_commits = 10  # Change this if you want more/fewer commits

    for _ in range(num_commits):
        random_time = generate_random_datetime(start_date, end_date)
        make_commit_at_time(random_time)

if __name__ == "__main__":
    main()
