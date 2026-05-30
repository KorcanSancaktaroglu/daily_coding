import cv2

# ✅ Automatically locate haarcascade from OpenCV's installation
cascade_xml = cv2.data.haarcascades + "haarcascade_frontalface_default.xml"
face_cascade = cv2.CascadeClassifier(cascade_xml)

# ✅ Check if the file was loaded successfully
if face_cascade.empty():
    raise IOError("ERROR: Failed to load Haarcascade XML file!")

video_capture = cv2.VideoCapture(0)

# ✅ Check if the camera opened successfully
if not video_capture.isOpened():
    raise IOError("ERROR: Cannot open camera! Is the webcam connected?")

print("Camera started. Press 'q' to exit.")

while True:
    ret, frame = video_capture.read()

    # ✅ Break the loop if the frame is not read properly to prevent a crash
    if not ret or frame is None:
        print("Failed to grab camera frame, exiting...")
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # ✅ More accurate detection using scaleFactor and minNeighbors
    faces_detected = face_cascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(35, 35)
    )

    for (x, y, w, h) in faces_detected:
        cv2.rectangle(frame, (x, y), (x + w, y + h), (0, 255, 0), 2)

        # ✅ Write the text ABOVE the face so it doesn't overlap on small faces
        label_y = y - 10 if y - 10 > 10 else y + 20
        cv2.putText(frame, "Face Detected", (x, label_y),
                    cv2.FONT_HERSHEY_COMPLEX, 0.8, (0, 255, 0), 2)

    cv2.imshow('Python Face Detection - Image Processing', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# ✅ Release resources
video_capture.release()
cv2.destroyAllWindows()
