;; Auto-generated. Do not edit!


(when (boundp 'rumba_msg::TargetPosition)
  (if (not (find-package "RUMBA_MSG"))
    (make-package "RUMBA_MSG"))
  (shadow 'TargetPosition (find-package "RUMBA_MSG")))
(unless (find-package "RUMBA_MSG::TARGETPOSITION")
  (make-package "RUMBA_MSG::TARGETPOSITION"))
(unless (find-package "RUMBA_MSG::TARGETPOSITIONREQUEST")
  (make-package "RUMBA_MSG::TARGETPOSITIONREQUEST"))
(unless (find-package "RUMBA_MSG::TARGETPOSITIONRESPONSE")
  (make-package "RUMBA_MSG::TARGETPOSITIONRESPONSE"))

(in-package "ROS")





(defclass rumba_msg::TargetPositionRequest
  :super ros::object
  :slots (_target_x _target_y _target_theta ))

(defmethod rumba_msg::TargetPositionRequest
  (:init
   (&key
    ((:target_x __target_x) 0.0)
    ((:target_y __target_y) 0.0)
    ((:target_theta __target_theta) 0.0)
    )
   (send-super :init)
   (setq _target_x (float __target_x))
   (setq _target_y (float __target_y))
   (setq _target_theta (float __target_theta))
   self)
  (:target_x
   (&optional __target_x)
   (if __target_x (setq _target_x __target_x)) _target_x)
  (:target_y
   (&optional __target_y)
   (if __target_y (setq _target_y __target_y)) _target_y)
  (:target_theta
   (&optional __target_theta)
   (if __target_theta (setq _target_theta __target_theta)) _target_theta)
  (:serialization-length
   ()
   (+
    ;; float64 _target_x
    8
    ;; float64 _target_y
    8
    ;; float64 _target_theta
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _target_x
       (sys::poke _target_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _target_y
       (sys::poke _target_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _target_theta
       (sys::poke _target_theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _target_x
     (setq _target_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _target_y
     (setq _target_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _target_theta
     (setq _target_theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass rumba_msg::TargetPositionResponse
  :super ros::object
  :slots (_linear_x _angular_z _feedback _message ))

(defmethod rumba_msg::TargetPositionResponse
  (:init
   (&key
    ((:linear_x __linear_x) 0.0)
    ((:angular_z __angular_z) 0.0)
    ((:feedback __feedback) nil)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _linear_x (float __linear_x))
   (setq _angular_z (float __angular_z))
   (setq _feedback __feedback)
   (setq _message (string __message))
   self)
  (:linear_x
   (&optional __linear_x)
   (if __linear_x (setq _linear_x __linear_x)) _linear_x)
  (:angular_z
   (&optional __angular_z)
   (if __angular_z (setq _angular_z __angular_z)) _angular_z)
  (:feedback
   (&optional (__feedback :null))
   (if (not (eq __feedback :null)) (setq _feedback __feedback)) _feedback)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; float64 _linear_x
    8
    ;; float64 _angular_z
    8
    ;; bool _feedback
    1
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _linear_x
       (sys::poke _linear_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _angular_z
       (sys::poke _angular_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _feedback
       (if _feedback (write-byte -1 s) (write-byte 0 s))
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _linear_x
     (setq _linear_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _angular_z
     (setq _angular_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _feedback
     (setq _feedback (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass rumba_msg::TargetPosition
  :super ros::object
  :slots ())

(setf (get rumba_msg::TargetPosition :md5sum-) "dd76aff00a72b33e8d77950fa07ebddf")
(setf (get rumba_msg::TargetPosition :datatype-) "rumba_msg/TargetPosition")
(setf (get rumba_msg::TargetPosition :request) rumba_msg::TargetPositionRequest)
(setf (get rumba_msg::TargetPosition :response) rumba_msg::TargetPositionResponse)

(defmethod rumba_msg::TargetPositionRequest
  (:response () (instance rumba_msg::TargetPositionResponse :init)))

(setf (get rumba_msg::TargetPositionRequest :md5sum-) "dd76aff00a72b33e8d77950fa07ebddf")
(setf (get rumba_msg::TargetPositionRequest :datatype-) "rumba_msg/TargetPositionRequest")
(setf (get rumba_msg::TargetPositionRequest :definition-)
      "float64 target_x
float64 target_y
float64 target_theta
---
float64 linear_x
float64 angular_z
bool feedback
string message

")

(setf (get rumba_msg::TargetPositionResponse :md5sum-) "dd76aff00a72b33e8d77950fa07ebddf")
(setf (get rumba_msg::TargetPositionResponse :datatype-) "rumba_msg/TargetPositionResponse")
(setf (get rumba_msg::TargetPositionResponse :definition-)
      "float64 target_x
float64 target_y
float64 target_theta
---
float64 linear_x
float64 angular_z
bool feedback
string message

")



(provide :rumba_msg/TargetPosition "dd76aff00a72b33e8d77950fa07ebddf")


