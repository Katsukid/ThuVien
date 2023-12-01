[%- BLOCK subtype_dropdowns -%]
 <select name="limit" class="subtype">
 [% IF ( limits.aud.size ) %]
 <option value="" class="menuheader">Tất cả bạn đọc</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Tất cả bạn đọc</option>
 [% END %]
 [% IF (limits.aud.0 == 'a' ) %]
 <option selected="selected" value="aud:a">Mầm non</option>
 [% ELSE %]
 <option value="aud:a">Mầm non</option>
 [% END %]
 [% IF (limits.aud.0 == 'b' ) %]
 <option value="aud:b" selected="selected">Tiểu học</option>
 [% ELSE %]
 <option value="aud:b">Tiểu học</option>
 [% END %]
 [% IF (limits.aud.0 == 'c' ) %]
 <option value="aud:c" selected="selected">Thiếu niên</option>
 [% ELSE %]
 <option value="aud:c">Thiếu niên</option>
 [% END %]
 [% IF (limits.aud.0 == 'd' ) %]
 <option value="aud:d" selected="selected">Thanh niên</option>
 [% ELSE %]
 <option value="aud:d">Thanh niên</option>
 [% END %]
 [% IF (limits.aud.0 == 'e' ) %]
 <option value="aud:e" selected="selected">Người lớn</option>
 [% ELSE %]
 <option value="aud:e">Người lớn</option>
 [% END %]
 [% IF (limits.aud.0 == 'f' ) %]
 <option value="aud:f" selected="selected">Chuyên ngành</option>
 [% ELSE %]
 <option value="aud:f">Chuyên ngành</option>
 [% END %]
 [% IF (limits.aud.0 == 'g' ) %]
 <option value="aud:g" selected="selected">Tổng hợp</option>
 [% ELSE %]
 <option value="aud:g">Tổng hợp</option>
 [% END %]
 [% IF (limits.aud.0 == 'j' ) %]
 <option value="aud:j" selected="selected">Vị thành niên</option>
 [% ELSE %]
 <option value="aud:j">Vị thành niên</option>
 [% END %]
 [% limits.delete( 'aud' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.fic.size OR limits.bio.size OR limits.mus.size ) %]
 <option value="" class="menuheader">Tất cả nội dung</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Tất cả nội dung</option>
 [% END %]
 [% IF (limits.fic.0 == '1' ) %]
 <option value="fic:1" selected="selected" >Viễn tưởng</option>
 [% ELSE %]
 <option value="fic:1" >Viễn tưởng</option>
 [% END %]
 [% IF (limits.fic.0 == '0' ) %]
 <option value="fic:0" selected="selected" >Non-fiction</option>
 [% ELSE %]
 <option value="fic:0" >Non-fiction</option>
 [% END %]
 [% IF (limits.bio.0 == 'b' ) %]
 <option value="bio:b" selected="selected" >Hồi ký, tiểu sử</option>
 [% ELSE %]
 <option value="bio:b" >Hồi ký, tiểu sử</option>
 [% END %]
 [% IF (limits.mus.0 == 'j' ) %]
 <option value="mus:j" selected="selected" >Bản thu âm</option>
 [% ELSE %]
 <option value="mus:j" >Bản thu âm</option>
 [% END %]
 [% IF (limits.mus.0 == 'i' ) %]
 <option value="mus:i" selected="selected" >Không phải bản thu âm</option>
 [% ELSE %]
 <option value="mus:i" >Không phải bản thu âm</option>
 [% END %]
 [% limits.delete( 'fic' ) %]
 [% limits.delete( 'bio' ) %]
 [% limits.delete( 'mus' ) %]
 </select>

 [% SET lformat = 'l-format' %]
 <select name="limit" class="subtype">
 [% IF ( limits.$lformat.size ) %]
 <option value="" class="menuheader">Tất cả định dạng</option>
 [% ELSE %]
 <option value="" selected="selected" class="menuheader">Tất cả định dạng</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ta' ) %]
 <option value="l-format:ta" selected="selected" >In thường</option>
 [% ELSE %]
 <option value="l-format:ta" >In thường</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tb' ) %]
 <option value="l-format:tb" selected="selected" >In khổ lớn</option>
 [% ELSE %]
 <option value="l-format:tb" >In khổ lớn</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'tc or fb' ) %]
 <option value="l-format:tc or fb" selected="selected" >Chữ nổi</option>
 [% ELSE %]
 <option value="l-format:tc or fb" >Chữ nổi</option>
 [% END %]
 <option value="" >-----------</option>
 [% IF (limits.$lformat.0 == 'sd' ) %]
 <option value="l-format:sd" selected="selected" >CD âm thanh</option>
 [% ELSE %]
 <option value="l-format:sd" >CD âm thanh</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'ss' ) %]
 <option value="l-format:ss" selected="selected" >Băng Cassette</option>
 [% ELSE %]
 <option value="l-format:ss" >Băng Cassette</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vf' ) %]
 <option value="l-format:vf" selected="selected" >Băng VHS</option>
 [% ELSE %]
 <option value="l-format:vf" >Băng VHS</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'vd' ) %]
 <option value="l-format:vd" selected="selected" >Đĩa DVD</option>
 [% ELSE %]
 <option value="l-format:vd" >Đĩa DVD</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'co' ) %]
 <option value="l-format:co" selected="selected" >CD phần mềm</option>
 [% ELSE %]
 <option value="l-format:co" >CD phần mềm</option>
 [% END %]
 [% IF (limits.$lformat.0 == 'cr' ) %]
 <option value="l-format:cr" selected="selected" >Website</option>
 [% ELSE %]
 <option value="l-format:cr" >Website</option>
 [% END %]
 [% limits.delete( 'l-format' ) %]
 </select>

 <select name="limit" class="subtype">
 [% IF ( limits.ctype.size ) %]
 <option value="" >Kiểu nội dung bổ sung</option>
 [% ELSE %]
 <option value="" selected="selected" >Kiểu nội dung bổ sung</option>
 [% END %]
 [% IF (limits.ctype.0 == 'a' ) %]
 <option value="ctype:a" selected="selected" >Tóm tắt / Tổng quát</option>
 [% ELSE %]
 <option value="ctype:a" >Tóm tắt / Tổng quát</option>
 [% END %]
 [% IF (limits.ctype.0 == 'b' ) %]
 <option value="ctype:b" selected="selected" >Thư mục</option>
 [% ELSE %]
 <option value="ctype:b" >Thư mục</option>
 [% END %]
 [% IF (limits.ctype.0 == 'c' ) %]
 <option value="ctype:c" selected="selected" >Catalogs</option>
 [% ELSE %]
 <option value="ctype:c" >Catalogs</option>
 [% END %]
 [% IF (limits.ctype.0 == 'e' ) %]
 <option value="ctype:e" selected="selected" >Bách khoa toàn thư </option>
 [% ELSE %]
 <option value="ctype:e" >Bách khoa toàn thư </option>
 [% END %]
 [% IF (limits.ctype.0 == 'f' ) %]
 <option value="ctype:f" selected="selected" >Handbooks</option>
 [% ELSE %]
 <option value="ctype:f" >Handbooks</option>
 [% END %]
 [% IF (limits.ctype.0 == 'g' ) %]
 <option value="ctype:g" selected="selected" >Bài viết pháp luật</option>
 [% ELSE %]
 <option value="ctype:g" >Bài viết pháp luật</option>
 [% END %]
 [% IF (limits.ctype.0 == 'i' ) %]
 <option value="ctype:i" selected="selected" >Chỉ dẫn</option>
 [% ELSE %]
 <option value="ctype:i" >Chỉ dẫn</option>
 [% END %]
 [% IF (limits.ctype.0 == 'j' ) %]
 <option value="ctype:j" selected="selected" >Tài liệu sáng chế</option>
 [% ELSE %]
 <option value="ctype:j" >Tài liệu sáng chế</option>
 [% END %]
 [% IF (limits.ctype.0 == 'k' ) %]
 <option value="ctype:k" selected="selected" >Danh sách đĩa nhạc</option>
 [% ELSE %]
 <option value="ctype:k" >Danh sách đĩa nhạc</option>
 [% END %]
 [% IF (limits.ctype.0 == 'l' ) %]
 <option value="ctype:l" selected="selected" >Pháp luật</option>
 [% ELSE %]
 <option value="ctype:l" >Pháp luật</option>
 [% END %]
 [% IF (limits.ctype.0 == 'm' ) %]
 <option value="ctype:m" selected="selected" >Luận án, luận văn</option>
 [% ELSE %]
 <option value="ctype:m" >Luận án, luận văn</option>
 [% END %]
 [% IF (limits.ctype.0 == 'n' ) %]
 <option value="ctype:n" selected="selected" >Tài liệu điều tra</option>
 [% ELSE %]
 <option value="ctype:n" >Tài liệu điều tra</option>
 [% END %]
 [% IF (limits.ctype.0 == 'o' ) %]
 <option value="ctype:o" selected="selected" >Bài phê bình</option>
 [% ELSE %]
 <option value="ctype:o" >Bài phê bình</option>
 [% END %]
 [% IF (limits.ctype.0 == 'p' ) %]
 <option value="ctype:p" selected="selected" >Tài liệu lập trình</option>
 [% ELSE %]
 <option value="ctype:p" >Tài liệu lập trình</option>
 [% END %]
 [% IF (limits.ctype.0 == 'q' ) %]
 <option value="ctype:q" selected="selected" >Tài liệu điện ảnh</option>
 [% ELSE %]
 <option value="ctype:q" >Tài liệu điện ảnh</option>
 [% END %]
 [% IF (limits.ctype.0 == 'r' ) %]
 <option value="ctype:r" selected="selected" >Danh bạ điện thoại</option>
 [% ELSE %]
 <option value="ctype:r" >Danh bạ điện thoại</option>
 [% END %]
 [% IF (limits.ctype.0 == 's' ) %]
 <option value="ctype:s" selected="selected" >Thống kê</option>
 [% ELSE %]
 <option value="ctype:s" >Thống kê</option>
 [% END %]
 [% IF (limits.ctype.0 == 't' ) %]
 <option value="ctype:t" selected="selected" >Báo cáo kỹ thuật</option>
 [% ELSE %]
 <option value="ctype:t" >Báo cáo kỹ thuật</option>
 [% END %]
 [% IF (limits.ctype.0 == 'v' ) %]
 <option value="ctype:v" selected="selected" >Ghi chú</option>
 [% ELSE %]
 <option value="ctype:v" >Ghi chú</option>
 [% END %]
 [% IF (limits.ctype.0 == 'w' ) %]
 <option value="ctype:w" selected="selected" >Báo cáo luật</option>
 [% ELSE %]
 <option value="ctype:w" >Báo cáo luật</option>
 [% END %]
 [% IF (limits.ctype.0 == 'z' ) %]
 <option value="ctype:z" selected="selected" >Điều ước quốc tế </option>
 [% ELSE %]
 <option value="ctype:z" >Điều ước quốc tế </option>
 [% END %]
 [% limits.delete( 'ctype' ) %]
 </select>
[%- END -%]
