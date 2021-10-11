from flask import Flask, json
from flask.ctx import RequestContext

app = Flask(__name__)

@app.route("/data", methods=['POST'])
def recieve_data_and_reply():
    return_val = {"success": False, "message": ""}
    try:
        data = json.loads(RequestContext.data)
        print(data)
    except Exception as e:
        return_val["message"] = "System has encountered an error." + e.__str__()
    return json.jsonify(return_val)

if __name__ == '__main__':
    app.run(debug=False, port=5200)