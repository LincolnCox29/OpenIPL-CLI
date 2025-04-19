import os

def main() -> None:
    dirs = [entry.name for entry in os.scandir("./examples") if entry.is_dir()]
    html = "<h1>OpenIPL Visual Test Report</h1>"
    for dir in dirs:
        html += f"""
        <div>
            <h3>{dir}</h3>
            <img src="./examples/{dir}/out.png" width="300">
        </div>
        """
    with open("./report.html", "w") as f:
        f.write(html)

if __name__ == "__main__":
    main()