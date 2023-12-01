 <select name="overlay_action" id="overlay_action">
 [% IF ( overlay_action_replace ) %]
 <option value="replace"  selected="selected">
 [% ELSE %]
 <option value="replace">
 [% END %] Thay thế biểu ghi thư mục hiện tại</option>
 [% IF ( overlay_action_create_new ) %]
 <option value="create_new" selected="selected">
 [% ELSE %]
 <option value="create_new">
 [% END %] Tạo biểu ghi</option>
 [% IF ( overlay_action_ignore ) %]
 <option value="ignore" selected="selected">
 [% ELSE %]
 <option value="ignore">
 [% END %] Bỏ qua biểu ghi (Tài liệu vẫn được xử lý)</option>
 </select>
