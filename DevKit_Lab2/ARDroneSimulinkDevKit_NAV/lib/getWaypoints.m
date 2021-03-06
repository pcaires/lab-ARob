function [ waypoint ] = getWaypoints(  )
%GETWAYPOINTS Generates a list of waypoints for the ARDrone
%   Each waypoint is a column vector that contains the desired position of the
%   drone, desired heading angle, and waiting time. The list of waypoints
%   is created combining the column vectors. 

% Number of waypoints. Edit this value as desired. 
nPoints = 10;

waypointsListARDrone = zeros(5,nPoints);

% Edit the following entries for k =1,2,...,nPoints
% waypointsListARDrone(:,k) = [ Xe (m), Ye (m), h (m), psi, waiting time (sec)
waypointsListARDrone(:,1) = [ 0.0; 0.0; 1.0; 0.0; 5.0]; % take off
waypointsListARDrone(:,2) = [ 0.5; 0.0; 1.0; 0.0; 5.0]; % go first corner 
waypointsListARDrone(:,3) = [ 0.5; 0.5; 1.0;pi/2; 5.0]; % go second corner 
waypointsListARDrone(:,4) = [ 0.0; 0.5; 1.0;pi/2; 5.0]; % go third corner 
waypointsListARDrone(:,5) = [ 0.0; 0.0; 1.0; 0.0; 5.0]; % go fourth corner
waypointsListARDrone(:,6) = [ 0.0; 0.0; 0.0; 0.0; 5.0]; % land 


waypoint = waypointsListARDrone ; 

end


% % % ORIGINAL
% % % waypointsListARDrone(:,1) = [ 0.0;0.0;1;0; 5] ; 
% % % waypointsListARDrone(:,2) = [-1.5;0;1;0; 0.1] ; 
% % % waypointsListARDrone(:,3) = [1.5;0;1;0; 0.1] ; 
% % % waypointsListARDrone(:,4) = [0;0;1;0; 2] ; 
% % % waypointsListARDrone(:,5) = [0;0;1.8;0; 5] ; 
% % % waypointsListARDrone(:,6) = [0;0;1;0; 5] ; 
% % % waypointsListARDrone(:,7) = [0;0;1;0; 5] ; 
% % % waypointsListARDrone(:,8) = [0;0;1;0; 5] ; 
% % % waypointsListARDrone(:,9) = [0;0;1;0; 5] ; 
% % % waypointsListARDrone(:,10) = [0;0;1;0; 5] ; 
% % % waypointsListARDrone(:,11) = [0;0;1;0; 5] ; 
