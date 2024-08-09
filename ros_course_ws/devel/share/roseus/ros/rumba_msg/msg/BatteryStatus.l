;; Auto-generated. Do not edit!


(when (boundp 'rumba_msg::BatteryStatus)
  (if (not (find-package "RUMBA_MSG"))
    (make-package "RUMBA_MSG"))
  (shadow 'BatteryStatus (find-package "RUMBA_MSG")))
(unless (find-package "RUMBA_MSG::BATTERYSTATUS")
  (make-package "RUMBA_MSG::BATTERYSTATUS"))

(in-package "ROS")
;;//! \htmlinclude BatteryStatus.msg.html


(defclass rumba_msg::BatteryStatus
  :super ros::object
  :slots (_percentage_battery _location_x _location_y _orientation_theta _brushes_up _debug_message ))

(defmethod rumba_msg::BatteryStatus
  (:init
   (&key
    ((:percentage_battery __percentage_battery) 0)
    ((:location_x __location_x) 0.0)
    ((:location_y __location_y) 0.0)
    ((:orientation_theta __orientation_theta) 0.0)
    ((:brushes_up __brushes_up) nil)
    ((:debug_message __debug_message) "")
    )
   (send-super :init)
   (setq _percentage_battery (round __percentage_battery))
   (setq _location_x (float __location_x))
   (setq _location_y (float __location_y))
   (setq _orientation_theta (float __orientation_theta))
   (setq _brushes_up __brushes_up)
   (setq _debug_message (string __debug_message))
   self)
  (:percentage_battery
   (&optional __percentage_battery)
   (if __percentage_battery (setq _percentage_battery __percentage_battery)) _percentage_battery)
  (:location_x
   (&optional __location_x)
   (if __location_x (setq _location_x __location_x)) _location_x)
  (:location_y
   (&optional __location_y)
   (if __location_y (setq _location_y __location_y)) _location_y)
  (:orientation_theta
   (&optional __orientation_theta)
   (if __orientation_theta (setq _orientation_theta __orientation_theta)) _orientation_theta)
  (:brushes_up
   (&optional (__brushes_up :null))
   (if (not (eq __brushes_up :null)) (setq _brushes_up __brushes_up)) _brushes_up)
  (:debug_message
   (&optional __debug_message)
   (if __debug_message (setq _debug_message __debug_message)) _debug_message)
  (:serialization-length
   ()
   (+
    ;; int64 _percentage_battery
    8
    ;; float64 _location_x
    8
    ;; float64 _location_y
    8
    ;; float64 _orientation_theta
    8
    ;; bool _brushes_up
    1
    ;; string _debug_message
    4 (length _debug_message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _percentage_battery
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _percentage_battery (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _percentage_battery) (= (length (_percentage_battery . bv)) 2)) ;; bignum
              (write-long (ash (elt (_percentage_battery . bv) 0) 0) s)
              (write-long (ash (elt (_percentage_battery . bv) 1) -1) s))
             ((and (class _percentage_battery) (= (length (_percentage_battery . bv)) 1)) ;; big1
              (write-long (elt (_percentage_battery . bv) 0) s)
              (write-long (if (>= _percentage_battery 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _percentage_battery s)(write-long (if (>= _percentage_battery 0) 0 #xffffffff) s)))
     ;; float64 _location_x
       (sys::poke _location_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _location_y
       (sys::poke _location_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _orientation_theta
       (sys::poke _orientation_theta (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _brushes_up
       (if _brushes_up (write-byte -1 s) (write-byte 0 s))
     ;; string _debug_message
       (write-long (length _debug_message) s) (princ _debug_message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _percentage_battery
#+(or :alpha :irix6 :x86_64)
      (setf _percentage_battery (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _percentage_battery (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; float64 _location_x
     (setq _location_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _location_y
     (setq _location_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _orientation_theta
     (setq _orientation_theta (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _brushes_up
     (setq _brushes_up (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _debug_message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _debug_message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get rumba_msg::BatteryStatus :md5sum-) "8553ab09064a977637e06a24726e1227")
(setf (get rumba_msg::BatteryStatus :datatype-) "rumba_msg/BatteryStatus")
(setf (get rumba_msg::BatteryStatus :definition-)
      "int64 percentage_battery
float64 location_x
float64 location_y
float64 orientation_theta
bool brushes_up
string debug_message

")



(provide :rumba_msg/BatteryStatus "8553ab09064a977637e06a24726e1227")


