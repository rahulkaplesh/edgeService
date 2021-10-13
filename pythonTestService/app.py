from flask import Flask, json, request
from flask.ctx import RequestContext

app = Flask(__name__)

@app.route("/data", methods=['POST'])
def recieve_data_and_reply():
    return_val = {"success": True, "message": "Hello World!!"}
    try:
        data = json.loads(request.data)
        print(data)
    except Exception as e:
        return_val["message"] = "System has encountered an error." + e.__str__()
    return json.jsonify(return_val)

if __name__ == '__main__':
    app.run(debug=False, port=5200)